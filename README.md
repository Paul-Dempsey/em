# EM

Work in Progress (WIP) EaganMatrix tools and library.

The EaganMatrix is the engine inside a number of devices.
These include the Haken Continuum, Continuu Mini, and Eagan Matrix Module from Haken Audio, and the Osmose from Expressive E.

- [Documentation](doc/index.md#em)

- [Buy pachde a coffee](https://venmo.com/u/pcdempsey). Thank you!

  Donations help pachde's morale, and fund hardware for testing and developing this software.\
  ![Buy pachde a coffee with VenMo](./doc/image/VenMo.png)

Pachde and this project are not officially affiliated with or sponsored by Haken Audio or Expressive E.

---

## About

This project intends to serve as a portable SDK for interfacing with EaganMatrix devices.

It includes tools, and a portable static library with a "C" ABI suitable for use from any language that can call C.

This project uses [Zig](https://ziglang.org/) as the build environment and source language for the tools.
The SDK itself (em-lib) is written in C/C++.
It aims to require minimal or no standard library support at runtime.
The `em-lib` is 'bring-your-own-allocator' (BYOA) and performs no memory management itself.

---

// Copyright © Paul Chase Dempsey\
![pachde (#d) logo](./doc/image/Logo.svg)
