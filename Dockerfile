# The robot controller runs 32-bit Debian Jessie, so cpu architecture and glibc must match
FROM i386/debian:buster AS build

# libhdf5-dev build-essential pkg-config are needed to compile the pytables hdf5 module
RUN apt-get update && apt-get install -y cmake libcurl4-gnutls-dev libxmlrpc-c++8-dev build-essential pkg-config

WORKDIR /src
ADD . .

WORKDIR /src/build
RUN cmake ..
RUN cmake --build .

# Copy to scratch image so only the binary is exported to host.
FROM scratch AS export
COPY --from=build /src/build/XmlRpcTest  /
CMD ["XmlRpcTest"]
