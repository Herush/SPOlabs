FROM ubuntu:latest

#COPY *.deb /tmp/
#RUN apt-get update && apt-get install -y /tmp/*.deb

COPY cicd/*.deb /tmp/

RUN apt-get update && \
    apt-get install -y /tmp/*.deb && \
    rm -rf /var/lib/apt/lists/*

RUN find / -name "laba1spo" 2>/dev/null

CMD ["usr/bin/laba1spo", "--success-param"]
