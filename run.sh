#!/usr/bin/env bash

VERSION=$(date +%s)

docker build . -t crucible:${VERSION} && \
	docker run --rm -i -t crucible:${VERSION}
