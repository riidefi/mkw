# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.222.0/containers/python-3/.devcontainer/base.Dockerfile

ARG VARIANT="3.11-bookworm"
FROM mcr.microsoft.com/vscode/devcontainers/python:1-${VARIANT}

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
    && apt-get -y install --no-install-recommends wine wine32 unzip ninja-build

# [Optional] Uncomment this line to install global node packages.
# RUN su vscode -c "source /usr/local/share/nvm/nvm.sh && npm install -g <your-package-here>" 2>&1

WORKDIR /blobs
ARG TOOLS_URL="https://www.dropbox.com/s/4b0hwciadfk8yuo/tools.zip?dl=1"
ADD ${TOOLS_URL} ./tools.zip
RUN mkdir -p ./artifacts/orig/pal \
    && echo "40cbee5ce207d8ca71b6611f8f7560e6f135562c25e8fa303f916011e99517ca tools.zip" | sha256sum --check --status \
    && unzip -o tools.zip \
    && rm tools.zip \
    && chmod +x ./tools/devkitppc/bin/powerpc-eabi-as \
    && chmod +x ./tools/devkitppc/bin/powerpc-eabi-gcc \
    && mv ./tools/blobs/* ./artifacts/orig/pal

# install devkitpro
WORKDIR /tmp/devkitpro
RUN mkdir -p /usr/local/share/keyring/ \
 && wget -O /usr/local/share/keyring/devkitpro-pub.gpg https://apt.devkitpro.org/devkitpro-pub.gpg \
 && echo "deb [signed-by=/usr/local/share/keyring/devkitpro-pub.gpg] https://apt.devkitpro.org stable main" > /etc/apt/sources.list.d/devkitpro.list \
 && apt-get update \
 && apt-get -y install devkitpro-pacman \
 && ln -s /proc/self/mounts /etc/mtab \
 && dkp-pacman -S --noconfirm wii-dev
