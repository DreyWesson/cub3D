FROM ubuntu:latest

# Update and install necessary packages
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    valgrind \
    libx11-dev \
    libxext-dev \
    libxrandr-dev \
    libxrender-dev \
    libbsd-dev \
    libssl-dev \
    libffi-dev \
    liblzma-dev \
    libbz2-dev \
    zsh \
    git

# Set the default shell to zsh
SHELL ["/bin/zsh", "-c"]

# Set the working directory
WORKDIR /app
