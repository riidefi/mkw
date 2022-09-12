# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.222.0/containers/python-3/.devcontainer/base.Dockerfile

# [Choice] Python version (use -bullseye variants on local arm64/Apple Silicon): 3, 3.10, 3.9, 3.8, 3.7, 3.6, 3-bullseye, 3.10-bullseye, 3.9-bullseye, 3.8-bullseye, 3.7-bullseye, 3.6-bullseye, 3-buster, 3.10-buster, 3.9-buster, 3.8-buster, 3.7-buster, 3.6-buster
ARG VARIANT="3.10-bullseye"
FROM mcr.microsoft.com/vscode/devcontainers/python:0-${VARIANT}

# [Choice] Node.js version: none, lts/*, 16, 14, 12, 10
ARG NODE_VERSION="none"
RUN if [ "${NODE_VERSION}" != "none" ]; then su vscode -c "umask 0002 && . /usr/local/share/nvm/nvm.sh && nvm install ${NODE_VERSION} 2>&1"; fi

# [Optional] If your pip requirements rarely change, uncomment this section to add them to the image.
COPY requirements.txt /tmp/pip-tmp/
RUN pip3 --disable-pip-version-check --no-cache-dir install -r /tmp/pip-tmp/requirements.txt \
    && rm -rf /tmp/pip-tmp

# [Optional] Uncomment this section to install additional OS packages.
RUN dpkg --add-architecture i386 \
    && apt-get update \
    && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends wine wine32 unzip

# [Optional] Uncomment this line to install global node packages.
# RUN su vscode -c "source /usr/local/share/nvm/nvm.sh && npm install -g <your-package-here>" 2>&1

WORKDIR /blobs
ARG TOOLS_URL="https://www.dropbox.com/s/4b0hwciadfk8yuo/tools.zip?dl=1"
ADD ${TOOLS_URL} ./tools.zip
RUN mkdir -p ./artifacts/orig/pal \
    && echo "3AB596ABBAE360ECABD3105E220159A9A54DAECF1B414A51EE1CD5D5A64191BF tools.zip" | sha256sum --check --status \
    && unzip -o tools.zip \
    && rm tools.zip \
    && chmod +x ./tools/devkitppc/bin/powerpc-eabi-as \
    && chmod +x ./tools/devkitppc/bin/powerpc-eabi-gcc \
    && mv ./tools/blobs/* ./artifacts/orig/pal

ARG NINJA_URL="https://github.com/ninja-build/ninja/releases/download/v1.11.1/ninja-win.zip"
ADD ${NINJA_URL} ./ninja.zip
RUN unzip -o ninja.zip \
    && rm ninja.zip
    && chmod +x ./ninja.exe
