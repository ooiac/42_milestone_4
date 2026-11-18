# NetPractice

*42 Common Core project by `caida-si`.*

NetPractice is a set of ten browser-based exercises on IPv4 networking. You don't write a network program; you configure addresses, subnet masks, gateways, and routes until the devices in each diagram can communicate.

## Networking concepts

- **IPv4 and CIDR:** the address and mask determine which part identifies the network and which part identifies the host.
- **Subnetting:** two hosts on the same subnet can communicate directly; hosts on different subnets need a route.
- **Gateways and routes:** the gateway must be reachable on the local network. A default route is used when no more specific route matches.
- **Routers and switches:** a switch joins devices on the same network; a router forwards packets between networks.

For example, in `192.168.1.0/24`, the `/24` mask leaves eight host bits. The network address is `192.168.1.0`, the broadcast address is `192.168.1.255`, and the usual usable host range is `.1`–`.254`. Assigning a valid address is only half the exercise: every intermediate router also needs a way to return traffic.

The early levels focus on addresses and masks, while later exercises require static routes across several routers. A quick way to debug a failed level is to follow the packet forward **and back** and inspect the route at each hop.

## Open the training interface

Requires Python 3 and a browser. From the directory containing the bundled `run.sh` script:

```sh
./run.sh
```

The script starts a local web server, normally using a free port starting at `49242`, and opens the browser. If it doesn't launch correctly:

```sh
python3 -m http.server 49242
```

Then open `http://localhost:49242` from that same directory.

1. Enter your 42 login in **Training** mode.
2. Configure the editable fields and click **Check again**.
3. Read the error log to see which connection is failing.
4. After solving a level, click **Get my config**.
5. Keep the exported configuration for each of the ten levels (`level1.json`, etc.) in the submission repository.

**Evaluation** mode gives random configurations. The documented evaluation uses three selected exercises from the harder levels with a time limit; check the current project subject for the official conditions.

## References

- [RFC 791 — IPv4](https://www.rfc-editor.org/rfc/rfc791)
- [RFC 1918 — private IPv4 address space](https://www.rfc-editor.org/rfc/rfc1918)
- `ip route` and `ip addr` manuals for seeing the same ideas on a Linux machine.

AI was used to structure and review the original documentation, not to solve or generate the network configuration files.
