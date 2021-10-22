ARG VERSION=102221

FROM jac18281828/cppdev:${VERSION} 

RUN export DEBIAN_FRONTEND=noninteractive && \
    apt update && \
    apt -y install build-essential cmake \
        gdb python3 clang-format

# build project
ARG PROJECT=crucible
WORKDIR /workspaces/${PROJECT}

COPY test test/
COPY include include/
COPY CMakeLists.txt .    

ARG BUILD=build
ARG TYPE=DEBUG

#build
ENV MAKEFLAGS=-j8
RUN cmake -H. -B${BUILD} -DPROJECT_NAME=${PROJECT} -DCMAKE_BUILD_TYPE=${TYPE} -DCMAKE_VERBOSE_MAKEFILE=on "-GUnix Makefiles"
RUN cmake --build ${BUILD} --verbose --config ${TYPE}
ENV CTEST_OUTPUT_ON_FAILURE=1

#RUN (cd ${BUILD} && ctest)
ENV PROJECT_NAME=${PROJECT}
CMD build/crucible_test
