#!/usr/bin/env bash

VERSION=$(date +%m%d%y)

docker build . -t crucible:${VERSION} && \
	docker run --rm -i -t crucible:${VERSION}
