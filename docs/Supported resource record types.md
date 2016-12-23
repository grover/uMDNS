# Supported Resource Record Types

Aside from the basic DNS RFCs there are additional record types and different
usages of these defined in various other RFCs. uMDNS does not support all DNS
or MDNS resource record types.

The following will describe the resource record types supported and provide some
examples as to using them:

* A Record
* TXT Record
* PTR Record
* SRV Record

[Contributions][3] that add support for other record types are welcome.

All record types, the respective structures and other constants are defined in
[records.h][1], which is automatically included with:

```C
#include <umdns/umdns.h>
```

The structures are purposely laid out in a way that enables them 
to be stored in read only memory. With the ability to store parts of them in
volatile memory (like )

## DNS record header

All DNS records share a common header, which is represented by `udns_record_t` in code:

```C
typedef struct umdns_record {
    const char*                 name;
    uint8_t                     type;
    const struct umdns_record** additional;
} umdns_record_t;
```

The record structure provides three fields:

Field | Description
------|------------
`name` | The NAME of the record as specified in [RFC 1035][2] section 4.1.3. The name is limited to 63 characters per label and 255 characters total. It must be zero terminated..
`type`  | The type of the record represented by the structure:<br>* `UMDNS_A_RECORD`<br>* `UMDNS_PTR_RECORD`<br>* `UMDNS_TXT_RECORD`<br>* `UMDNS_SRV_RECORD`
`additional` | A pointer to an additional record that adds to this record. Records referenced here will be reported as additional records in announcements and responses to queries for this record. The last entry has to be a `NULL` pointer. This pointer may be `NULL` if additional records are not used.

## A Resource Record

The A resource record, defined in [RFC 1035][2] section 3.4.1., maps a NAME to an IPv4 address.

```C
typedef struct umdns_a_record {
  umdns_record_t  record;
  uint32_t*       inaddr;
} umdns_a_record_t;
```

Field | Description
------|------------
`record` | The general resource record structure described above.
`inaddr` | A pointer to a 32 bit integer that contains the IPv4 address in host byte order.

### Example

```C
static uint32_t address = 0x7F000001;

static const umdns_a_record_t a_record = {
  .record = {
    .name = "localhost",
    .type = UMDNS_A_RECORD,
    .additional = NULL
  },
  .inaddr = &address
};
```

## TXT Record

The TXT resource record provides the ability to hold descriptive text. The
semantics depend on the domain and other DNS records. It is defined in 
[RFC 1035][2].

```C
typedef struct dns_txt_record {
  umdns_record_t    record;
  const char      **txt;
} dns_txt_record_t;
```

Field | Description
------|------------
`record` | The general resource record structure described above.
`txt` | A pointer to an array of character strings. Each string entry is limited to 255 characters. The last entry must be `NULL`.

### Example

```C
static const char *txt_values[] = {
    "Owner=Michael Froehlich",
    NULL
};

static const umdns_txt_record_t txt_record = {
  .record = {
    .name = "localhost",
    .type = UMDNS_TXT_RECORD,
    .additional = NULL
  },
  .txt = &txt_values[0]
};
```

## PTR Record

PTR records are defined in [RFC 1035][2]. These records are used in special domains
to point to some other location in the domain space. One use of PTR records are
reverse DNS lookups.

```C
typedef struct umdns_ptr_record {
  umdns_record_t   record;
  const char      *name;
} umdns_ptr_record_t;
```

Field | Description
------|------------
`record` | The general resource record structure described above.
`name` | Pointer to a zero terminated string that represents the NAME pointed to. The name is limited to 63 characters per label and 255 characters total.

### Example

```C
static const dns_ptr_record_t dns_hap_record = {
  .record = {
    .name = "127.0.0.1",
    .type = UMDNS_PTR_RECORD,
    .additional = NULL
  },
  .name = "localhost"
};
```

## SRV Record

The service resource record format is defined in [RFC 2782][4]. It is used
for DNS service discovery.

```C
/**
 * @brief DNS SRV record structure per RFC 2782.
 */
typedef struct umdns_srv_record {
  umdns_record_t  record;
  uint16_t        priority;
  uint16_t        weight;
  uint16_t        port;
  const char     *target;
} umdns_srv_record_t;
```

Field | Description
------|------------
`record` | The general resource record structure described above.
`priority` | The priority of the record in relation to other records.
`weight` | Weight is used to select servers with the same priority.
`port` | The port number of the service on the host.
`target` | The name of the the host that provides the service.

### Example

```C
static const umdns_srv_record_t ldap_srv_record = {
  .record = {
    .name = "_ldap._tcp.example.com",
    .type = UMDNS_SRV_RECORD,
    .additional = NULL
  },
  .priority = 0,
  .weight = 0,
  .port = 0,
  .target = "localhost"
};
```

# TTL Values

All MDNS announcements have a time to live field. This is usually a variable
that represents the remaining time a DNS resource record is valid. Including
the TTL as part of the structures described above prevents the goal of keeping
them in ROM.

This library uses a single TTL value (determined by `UMDNS_DEFAULT_TTL`) for
all record types (which is in conflict with [RFC 6762][5]) - however given the
purpose of acting as an MDNS responder in a microcontroller it is assumed that
the controller will be in a power saving mode most of the time. This encourages
short and unified TTL values to give up on resource records while the device is
in a low power state.

The default value of `UMDNS_DEFAULT_TTL` is 120 seconds. This can be changed
with the feature toggles using the [CMake build system][6]. The value is written
into the umdns_config.h file that is written as part of the build.

[1]: https://github.com/grover/uMDNS/tree/master/include/umdns/records.h
[2]: https://tools.ietf.org/rfc/rfc1035.txt
[3]: https://github.com/grover/uMDNS/tree/master/CONTRIBUTING.md
[4]: https://tools.ietf.org/rfc/rfc2782.txt
[5]: https://tools.ietf.org/rfc/rfc6762.txt
[6]: https://github.com/grover/uMDNS/tree/master/docs/Feature%20Toggles.md
