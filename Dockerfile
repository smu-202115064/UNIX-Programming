# Download base image ubuntu 20.04
FROM ubuntu:20.04

# LABEL about the custom image
LABEL maintainer="김동주"
LABEL version="0.0.2"
LABEL description="[Seoul] UNIX Programming (HAEA0014 (1)) [2nd Semester] 수업에서 사용할 실습환경입니다."

# Disable Prompt During Packages Installation
ARG DEBIAN_FRONTEND=noninteractive

# Update Ubuntu Software repository
RUN apt update
RUN apt-get install man-db -y
