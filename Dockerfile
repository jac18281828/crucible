FROM jac18281828/cppdev:latest

ARG PROJECT=crucible

WORKDIR /workspaces/${PROJECT}
COPY . .
RUN chown -R jac.jac .
USER jac
ARG BUILD=build
ARG TYPE=DEBUG

RUN mkdir -p ${BUILD}
#build
ENV MAKEFLAGS=-j8
RUN cmake -H. -B${BUILD} -DPROJECT_NAME=${PROJECT} -DCMAKE_BUILD_TYPE=${TYPE} -DCMAKE_VERBOSE_MAKEFILE=on "-GUnix Makefiles"
RUN cmake --build ${BUILD} --verbose --config ${TYPE}
ENV CTEST_OUTPUT_ON_FAILURE=1
#RUN (cd ${BUILD} && ctest)
ENV PROJECT_NAME=${PROJECT}
CMD build/main
