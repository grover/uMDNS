# uMDNS

[![Build Status](https://travis-ci.org/grover/uMDNS.svg?branch=master)][1]
[![Coverity Scan Build Status](https://scan.coverity.com/projects/11239/badge.svg)][10]
[![Documentation Status](https://readthedocs.org/projects/umdns/badge/?version=latest)][11]

This is an implementation of an [RFC6762 MDNS responder][2] for low power, low 
memory microcontrollers. It's primary use is with the [HomeKit Accessory
Framework][3], but has several properties that may be of interest for other projects.

- Static memory layout, moving most DNS records to ROM
- Independent of a specific UDP/IP stack implementation

It's been built and tested for several platforms. There're some examples, which
show the general usage idea.

## Prerequisites

* [CMake 3.2][4]
* A C99 compiler for your platform that's supported by CMake

## Getting the code

This project uses [git submodules][13]. Use:

    git clone --recursive https://github.com/grover/uMDNS

Please make sure that you use a version of Git that has submodule support.

## Building

Build instructions vary by platform. In some cases you may want to integrate
uMDNS into your project. Please consult [Build Instructions][5]
for details.

## Running the tests

Tests do not require an active network connection and will not interfere with
your local MDNS network. The tests are provided in a set of executables in the 
[test/][6] folder.


## Contributing

Please read [CONTRIBUTING.md][7] for details on our code of conduct,
and the process for submitting pull requests to us. Any contributions are welcome
and please add yourself to the contributor list at [CONTRIBUTORS.md][8].

## License

This project is licensed under the MIT License - see the [LICENSE.md][9] file for details.

## Acknowledgments

This project uses code that has been created by others in the open source community:

* This project uses [Unity - Simple Unit Testing for C][12]

The licenses of the respective projects apply.

[1]: https://travis-ci.org/grover/uMDNS "Travis CI Build Status"
[2]: https://tools.ietf.org/html/rfc6762 "RFC 6762"
[3]: http://github.com/grover/HomeKitAccessoryFramework
[4]: http://cmake.org
[5]: docs/Building.md
[6]: tests/
[7]: CONTRIBUTING.md
[8]: CONTRIBUTORS.md
[9]: LICENSE.md
[10]: https://scan.coverity.com/projects/grover-umdns
[11]: http://umdns.readthedocs.io/en/latest/?badge=latest
[12]: https://github.com/ThrowTheSwitch/Unity
[13]: https://git-scm.com/book/en/v2/Git-Tools-Submodules
