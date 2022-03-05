## Simple Onion Generation

This tool generates random V2 & V3 .onion addresses.

## How to Compile

- Clone the repo
  - `git clone https://github.com/h3ssan/sog`
  - `cd sog`
- Build using CMake
  - `mkdir build && cd build`
  - `cmake -DCMAKE_BUILD_TYPE=Release ..`
- Compile using make
  - `make`
- Install the binary
  - `make install` P.S. You'll need privilege permissions.
- Run it globally
  - `sog`

## How to Identify Onion V3 Addresses

- They're 56 long characters.
- Always ends with the letter 'D'.