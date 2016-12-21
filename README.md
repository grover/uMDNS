microMDNS
=

This is an implementation of an MDNS responder for low power, low 
memory microcontrollers. It's primary use is with the [HomeKit Accessory
Framework](http://github.com/grover/HomeKitAccessoryFramework), but has several
properties that may be of interest for other projects.

- Static memory layout, moving most DNS records to ROM
- Independent of a specific UDP/IP stack implementation

It's been built and tested for several platforms. There're some examples, which
show the general usage idea.

Prerequisites
=

* [CMake 3.5](http://cmake.org)
* A C99 compiler for your platform that's supported by CMake

Building
=

Build instructions vary by platform. In some cases you may want to integrate
microMDNS into your project. Please consult [Build Instructions](docs/Building.md)
for details.

Running the tests
=

Tests do not require an active network connection and will not interfere with
your local MDNS network. The tests are provided in a set of executables in the 
[test/](tests/) folder.


Contributing
=

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct,
and the process for submitting pull requests to us. Any contributions are welcome
and please add yourself to the contributor list at [CONTRIBUTORS.md](CONTRIBUTORS.md).

License
=

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
