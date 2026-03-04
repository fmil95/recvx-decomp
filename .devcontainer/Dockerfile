FROM mcr.microsoft.com/devcontainers/cpp:2-debian13

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="none"

# Install MIPS
RUN apt-get update \
    && apt-get install -y binutils-mips-linux-gnu binutils-mipsel-linux-gnu

# Download the wibo decompilation tool, make it executable, and move it to /usr/bin.
RUN wget https://github.com/decompals/wibo/releases/download/1.0.0/wibo-x86_64 \
    && chmod +x wibo-x86_64 \
    && sudo mv wibo-x86_64 /usr/bin/wibo

# Optionally install the cmake for vcpkg
COPY ./reinstall-cmake.sh /tmp/

RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
        chmod +x /tmp/reinstall-cmake.sh && /tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
    fi \
    && rm -f /tmp/reinstall-cmake.sh

# [Optional] Uncomment this section to install additional vcpkg ports.
# RUN su vscode -c "${VCPKG_ROOT}/vcpkg install <your-port-name-here>"

# [Optional] Uncomment this section to install additional packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>
