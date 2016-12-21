uMDNS
=

The following files describe the API of the uMDNS responder and the dependencies it has to the project that includes it.

API Documentation
=

The header files of this project are documented using Doxygen. The file API.md contains an overview of the uMDNS API 
and gives a rough first idea on the usage of this API.

Network interface
=

uMDNS does not provide or depend upon a specific network interface. This was a primary design goal of this project to
massively limit the external dependencies. This allows us to port the MDNS responder to various embedded platforms, run it
on regular operating systems and on hardware without an operating system.

A huge benefit of this is that uMDNS is easily fuzzed, which ensures that the MDNS responder is tolerant to any inputs, 
does not crash and enhances the security of the implementation.

A draw back is that any integrating system has to implement the proper network abstractions. See the configuration section
below for details and examples.

Configuration
=

uMDNS is externally configured and can be customized to work in different scenarios. This mechanism and several examples
are provided in the [examples/](../examples/) folder.
