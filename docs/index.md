uMDNS - An MDNS responder for connected microcontrollers

This is an implementation of an [RFC 6762 MDNS responder][rfc6762] for low power, low
memory microcontrollers. It's primary use is with the [HomeKit Accessory
Framework][haf], but has several properties that may be of interest for other projects:

- Static memory layout, moving most DNS records to ROM
- Independent of a specific UDP/IP stack implementation

It's been built and tested for several platforms. There're some examples, which
show the general usage idea.

[rfc6762]: https://tools.ietf.org/html/rfc6762
[haf]: http://github.com/grover/HomeKitAccessoryFramework
