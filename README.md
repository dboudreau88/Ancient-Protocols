# Ancient Protocols Worth Reviving

A curated collection of old, defunct, or underused network protocols that hold
interesting ideas for modern software. Organized by category with notes on
revival potential.

---

## 1. Instant Messaging & Presence

| Protocol | Era | Description | Interesting Quality | Revival Potential | Status |
|----------|-----|-------------|--------------------|--------------------|--------|
| **OSCAR** | 1997-2017 | AOL's binary IM protocol (AIM/ICQ). FLAP/SNAC framing, buddy lists, file transfer, presence. | Rich feature set: buddy lists, file transfer, chat rooms, typing indicators, idle time. Binary but well-structured. | **High** - NINA wiki community actively documenting it. Open OSCAR Server exists. | Dead (official), community revival |
| **TOC** | 1990s | Text-based gateway to OSCAR. Simpler alternative for lighter clients. | Easy to reimplement. Good for CLI-first or embedded messaging. | **Medium** - Good for lightweight/nostalgic clients. | Dead |
| **MSNP** | 1999-2012 | Microsoft Notification Protocol (MSN Messenger). Text-based, switchboard chats. | Clean text protocol. Switchboard concept for group chats was elegant. | **Medium** - Reverse-engineered by community. Pidgin/libpurple had support. | Dead |
| **YMSG** | 1998-2016 | Yahoo Messenger protocol. Chat rooms, file transfer, voice. | Chat rooms were legendary. Multi-party conferencing built in. | **Medium** - Partially documented. Nostalgic chatroom culture. | Dead |
| **XMPP/Jabber** | 1999-present | Open standard for presence + messaging. Federated by design. | Federation model (like email). Extensible via XEPs. Jingle adds VoIP/video. | **High** - Already open standard. Underused, not dead. Needs modern UX. | Alive (niche) |
| **ICQ/UIN** | 1996-2024 | Original ICQ protocol before OSCAR unification. | First widely-used IM protocol. UIN numbering system was novel. | **Low** - Superseded by OSCAR. | Dead (2024) |
| **Gadu-Gadu** | 2000-present | Polish IM protocol. Huge in Poland, unknown elsewhere. | Interesting as a case study of regional protocol survival. Simple binary protocol. | **Low** - Very niche. | Alive (Poland) |
| **Sametime** | 1998-present | IBM/Lotus enterprise IM. Presence + meeting integration. | Enterprise-grade presence. Meeting scheduling baked into the protocol. | **Low** - Enterprise-locked. | Alive (HCL) |
| **PowWow** | 1990s | Tribal Voice's IM client. Competed with AIM before being crushed. | Early voice chat integration. Room-based chatting. | **Low** - No documentation. | Dead |

---

## 2. Peer-to-Peer & File Sharing

| Protocol | Era | Description | Interesting Quality | Revival Potential | Status |
|----------|-----|-------------|--------------------|--------------------|--------|
| **Gnutella** | 2000-ongoing | Fully decentralized P2P. Query flooding, no central index. | Anti-censorship by design. No single point of failure. Ultrapeer architecture for scalability. | **High** - Still has clients. Community active. | Alive (small) |
| **FastTrack** | 2001 | Semi-decentralized P2P (Kazaa, Grokster). Supernode architecture. | Supernode concept: powerful users become indexing hubs. Elegant load distribution. | **Medium** - Interesting model but proprietary history. | Dead |
| **Napster/OpenNAP** | 1999-2001 | Central index P2P for music. | First mass-market P2P. OpenNAP protocol spawned WinMX community. | **Medium** - OpenNAP still has community. Federated Napster concept. | Dead/Alive (OpenNAP) |
| **eDonkey2000** | 2000-ongoing | Hash-based file sharing, multipart chunked downloads. | Content-addressed before it was cool. Credit system for uploaders. | **Medium** - MLDonkey/eMule still running. | Alive (small) |
| **Freenet** | 2000-present | Anonymous, censorship-resistant distributed datastore. | Stores encrypted data on participants without their knowledge. Darknet mode for friend-to-friend. | **High** - Privacy focus is more relevant than ever. Still developed. | Alive |
| **Soulseek** | 2000-present | Music-focused sharing with persistent chat rooms. | Niche music community. Search by directory browsing. Chat rooms organized by genre. | **High** - Still running, cult following. Nicotine+ client actively developed. | Alive |
| **Direct Connect** | 2000-present | Hub-based P2P with minimum share requirements. | Forced sharing ratio. Hub-based communities with rules. Text-based protocol. | **Medium** - DC++ still active. ADC (Advanced DC) is an improved version. | Alive (small) |
| **WinMX** | 2000-2005 | P2P using WPNP and OpenNAP protocols. | Dual-network design. Peer caching for NAT traversal. | **Low** - Community-run servers exist but fading. | Dying |
| **Ares Galaxy** | 2002-present | Decentralized P2P using its own protocol. | Lightweight. Built-in media player. Private tracker model. | **Low** - Niche. | Alive (small) |
| **RetroShare** | 2006-present | Friend-to-friend encrypted P2P. | Only connects to people you trust. Built-in chat, forums, file sharing. Darknet by default. | **High** - Privacy-first design. Active development. | Alive |
| **Tox** | 2013-present | Encrypted P2P messenger using DHT. | No servers at all. End-to-end encrypted by default. | **High** - Modern privacy concerns make this relevant. | Alive |
| **WASTE** | 2003-2005 | Justin Frankel's (Winamp creator) encrypted darknet tool. | Small trusted networks. Encrypted P2P. Created by a legend. | **Medium** - Interesting concept, needs modern reimplementation. | Dead |
| **MUTE** | 2002-present | Anonymous file sharing via encrypted P2P routing. | Message routing through intermediate nodes hides source/destination. | **Medium** - Anonymity concept is ahead of its time. | Dying |

---

## 3. Bulletin Board / Terminal / Serial

| Protocol | Era | Description | Interesting Quality | Revival Potential | Status |
|----------|-----|-------------|--------------------|--------------------|--------|
| **ZMODEM** | 1986 | Serial file transfer with resume, 32-bit CRC, auto-start. | Resume interrupted transfers. Crash recovery. 8KB blocks. Dominated BBS world. | **High** - Active retro-computing community. WiModem232 uses it. | Alive (retro) |
| **Kermit** | 1981 | Transport-independent file transfer + terminal emulation. | Works over anything: serial, TCP/IP, X.25, modem. Built-in scripting language. Embedded device use. | **High** - Still maintained at kermitproject.org. E-Kermit for embedded. | Alive |
| **XMODEM** | 1977 | Original serial file transfer. 128-byte blocks, simple checksum. | Simplicity itself. Maximum compatibility. The "hello world" of file transfer. | **Medium** - Maximum compatibility for vintage hardware. | Alive (retro) |
| **YMODEM** | 1985 | XMODEM successor with 1K blocks, batch transfer, CRC-16. | Batch file transfer. Header packet with filename/size. | **Medium** - Better than XMODEM for retro use. | Alive (retro) |
| **BBS Door Protocols** | 1980s-90s | Synchronet, Renegade, Mystic BBS protocols for games/apps. | Doors created a platform-within-a-platform ecosystem. Multiplayer BBS games. | **Medium** - Active BBS revival scene (Telnet BBS Guide). | Alive (retro) |
| **ANSI/VT100 Terminal** | 1970s-present | Terminal escape code protocols. | Color graphics over text. BBS art culture. Still used in terminal emulators. | **Medium** - BBS art community thrives. Terminal is eternal. | Alive |

---

## 4. Information Retrieval & Documents

| Protocol | Era | Description | Interesting Quality | Revival Potential | Status |
|----------|-----|-------------|--------------------|--------------------|--------|
| **Gopher** | 1991-ongoing | Menu-based document retrieval. Pre-web competitor. | Structured navigation. No HTML bloat. Server-defined menus. | **High** - ~160 active servers. Overbite Project. Gemini is its spiritual successor. | Alive (small) |
| **NNTP/Usenet** | 1980s-ongoing | Decentralized newsgroup discussion system. | Federated moderation. Threaded discussions before forums. Binary groups for file sharing. | **Medium** - Still used for binaries. Text groups declining but functional. | Alive (declining) |
| **Finger** | 1977 | User status/presence information. `.plan` files. | Original "presence" protocol. `.plan` files as personal blogs. Simple and human-friendly. | **High** - Hackaday covered it in 2025. Anti-tracking presence alternative. "Fingerverse" concept. | Mostly dead |
| **Ph/Apollo** | 1980s | Phone directory lookup protocol. | Federated directory service. Simple presence/directory concept. | **Low** - Concept absorbed by LDAP and modern directories. | Dead |
| **Gemini** | 2019-present | Modern Gopher successor. TLS by default, simplified HTTP. | Intentionally limited design. No JavaScript, no cookies, no tracking. | **High** - Growing community. Proves the model works. | Alive (growing) |
| **Veronica/Archie** | 1990s | Search engines for Gopher/FTP. | Pre-Google search. Subject-based indexing. | **Low** - Concept lives in modern search. | Dead |

---

## 5. Real-Time Communication & VoIP

| Protocol | Era | Description | Interesting Quality | Revival Potential | Status |
|----------|-----|-------------|--------------------|--------------------|--------|
| **IAX** | 2004 | Inter-Asterisk Exchange. VoIP using single port for signaling + media. | NAT-friendly by design. Single UDP port for everything. Trunking between servers. | **High** - Simpler than SIP. Still used in Asterisk. | Alive (niche) |
| **H.323** | 1996 | ITU VoIP standard. Predecessor to SIP. | Battle-tested. Still in some enterprise/video conferencing. Well-understood. | **Low** - Superseded by SIP. Complex but proven. | Declining |
| **Jingle** | 2005 | XMPP extension for P2P VoIP/video signaling. | Google Talk used it. Open standard. Uses ICE for NAT traversal. | **Medium** - libjingle is open source. Underused. | Alive (niche) |
| **SKINNY** | 2000s | Cisco SCCP. Lightweight endpoint control protocol. | Simple station control. Less overhead than SIP for Cisco environments. | **Low** - Cisco-locked. | Alive (Cisco) |
| **MGCP** | 1999 | Media Gateway Control Protocol. Centralized call control. | Decomposes gateway intelligence. Useful for carrier-grade deployments. | **Low** - Specialized use case. | Alive (carriers) |

---

## 6. Email (Old & Defunct)

| Protocol | Era | Description | Interesting Quality | Revival Potential | Status |
|----------|-----|-------------|--------------------|--------------------|--------|
| **UUCP** | 1979-present | Unix-to-Unix Copy. Store-and-forward over dial-up. | Delayed delivery model. Route-based addressing (`host1!host2!user`). Worked without persistent connections. | **High** - Hackaday covered it in 2025. Great for low-connectivity scenarios. | Alive (very niche) |
| **POP2** | 1985 | Post Office Protocol v2. Simple mail retrieval. | Simpler than POP3. No permanent storage on server. | **Low** - POP3 superseded it completely. | Dead |
| **X.400** | 1984 | ITU/OSI email standard. | Rich addressing (O/R addresses). Built-in security features. Mandated by governments. | **Low** - Lost to SMTP. Still in some military/gov systems. | Dying |
| **MHS** | 1986 | Message Handling System (Novell). | Integrated with NetWare directory. Gateway to other email systems. | **Low** - Novell abandoned it. | Dead |
| **Phonenet** | 1981 | CSNET's dial-up mail relay. | Provided email to machines without ARPANET access. Store-and-forward over phone lines. | **Low** - Historical significance only. | Dead |
| **Coloured Book Protocols** | 1975-1992 | UK academic email protocols. | JNT Mail, Grey Book, etc. Ran on academic networks. | **Low** - Historical only. | Dead |
| **MH** | 1977 | Message Handler. Unix email user agent. | Each message is a file. Composable with shell tools. CLI-first design. | **Medium** - Still maintained. Inspires modern CLI email tools (mujmap, himalaya). | Alive (niche) |

---

## 7. File Systems & LAN Sharing

| Protocol | Era | Description | Interesting Quality | Revival Potential | Status |
|----------|-----|-------------|--------------------|--------------------|--------|
| **AFP** | 1985-2025 | Apple Filing Protocol. Mac-native file sharing. | Preserved resource forks and Mac metadata. Automatic service discovery via AppleTalk. | **Low** - Being removed from macOS 27. Superseded by SMB3. | Dying |
| **NCP** | 1983 | Novell NetWare Core Protocol. | Fast for its era. Directory services (NDS). Login scripts. | **Low** - NetWare is dead. Novell OES kept it alive until 2009. | Dead |
| **IPX/SPX** | 1980s-2000s | Novell's network layer protocol. | Simple addressing. Broadcast-based service discovery. Dominated LAN gaming. | **Medium** - Gaming nostalgia. Still used in some industrial systems. | Mostly dead |
| **AppleTalk** | 1985-2000s | Apple's LAN protocol suite. | Zero-configuration networking before it was a buzzword. Auto-addressing. | **Medium** - Ideas live on in Bonjour/mDNS. Historical significance. | Dead |
| **DECnet** | 1975-2000s | DEC's networking protocol. | Phase IV routing was elegant. DNA (DecNet Architecture) was comprehensive. | **Low** - DEC is gone. Concepts absorbed into OSI. | Dead |
| **XNS** | 1981 | Xerox Network Systems. | Influenced TCP/IP, IPX, and AppleTalk. Datagram + sequenced packet model. | **Low** - Historical only. | Dead |
| **SNA** | 1974-present | IBM Systems Network Architecture. | Hierarchical networking. Still in mainframe environments. | **Low** - Mainframe-locked. | Alive (mainframes) |
| **LAT** | 1983 | DEC Local Area Transport. | Terminal server protocol. Non-routable but efficient for local clusters. | **Low** - Legacy DEC environments only. | Dead |
| **Banyan VINES** | 1984-1999 | Virtual Network Operating System. | StreetTalk directory was global and hierarchical. Advanced for its time. | **Low** - Company is gone. | Dead |
| **SMB1** | 1983 | Original Server Message Block. | Simple file sharing. Cross-platform via Samba. | **Medium** - Still the basis of modern SMB. Historical interest. | Superseded |
| **9P** | 1992 | Plan 9's distributed file protocol. | Everything is a file. Namespace-based resource access. | **Medium** - Used in Linux (virtio-9p). Modern IoT relevance. | Alive (niche) |

---

## 8. Printing

| Protocol | Era | Description | Interesting Quality | Revival Potential | Status |
|----------|-----|-------------|--------------------|--------------------|--------|
| **LPD/LPR** | 1983 | Line Printer Daemon/Remote. Berkeley Unix printing. | Simple queue-based model. Control file + data file separation. | **Medium** - Still in CUPS. Being removed from FreeBSD (2026). | Declining |
| **AppSocket/JetDirect** | 1990s | Raw TCP port 9100 printing. | Dead simple: send data to port 9100. No handshake. | **High** - Still the most common network printing method. | Alive |
| **PAP (AppleTalk)** | 1980s | Printer Access Protocol. AppleTalk printer sharing. | Printer discovery was automatic. Status messages to user. | **Low** - Dead with AppleTalk. | Dead |
| **SNMP Printing** | 1990s | Using SNMP to query printer status. | Standardized printer monitoring. Supply levels, page counts. | **Medium** - Still used alongside IPP. | Alive |

---

## 9. Service Discovery

| Protocol | Era | Description | Interesting Quality | Revival Potential | Status |
|----------|-----|-------------|--------------------|--------------------|--------|
| **SLP** | 1997 | Service Location Protocol. LAN service discovery without central directory. | Open standard. Scopes for organizing services. Dynamic registration. | **Medium** - Alternative to mDNS/Bonjour. Simpler in some ways. | Alive (niche) |
| **mDNS/DNS-SD/Bonjour** | 1999-present | Multicast DNS + DNS Service Discovery. Zero-configuration networking. | Plug-and-play device discovery. Works without infrastructure. | **High** - Already alive and thriving. IoT essential. | Alive |
| **WS-Discovery** | 2004 | Web Services Discovery. XML-based device announcement. | SOAP-based discovery for enterprise. | **Low** - Overly complex. mDNS won. | Declining |
| **SSDP** | 1999 | Simple Service Discovery Protocol (UPnP). | Auto-discovery of UPnP devices. | **Medium** - Still in use for home routers/media devices. | Alive |
| **NetBIOS** | 1983 | Network Basic Input/Output System. Name resolution + session. | Simple name-based addressing. Broadcast discovery. | **Low** - Legacy Windows networking. | Declining |

---

## 10. Gaming

| Protocol | Era | Description | Interesting Quality | Revival Potential | Status |
|----------|-----|-------------|--------------------|--------------------|--------|
| **IPX/SPX (Gaming)** | 1990s | LAN protocol used by Doom, Quake, Diablo. | Low-latency LAN gaming. Broadcast-based server discovery. | **Medium** - Retro gaming community keeps it alive via wrappers. | Mostly dead |
| **GameSpy Protocol** | 1999-2013 | Master server for game matchmaking. | Centralized server browser. NAT traversal helpers. | **Low** - GameSpy shut down. Community replacements exist (OpenSpy). | Dead |
| **Kali** | 1990s-2000s | Tunneling IPX over TCP/IP for LAN games over internet. | Clever protocol translation. Enabled LAN games online. | **Medium** - Concept useful for retro gaming. | Mostly dead |
| **Aido** | 1990s | Sega's online gaming protocol (Dreamcast). | Early console online gaming. | **Low** - Console-specific. | Dead |
| **GameRanger** | 1999-present | macOS game matchmaking service. | Peer-to-peer connection brokering. Still running. | **Low** - Niche (macOS gaming). | Alive (niche) |

---

## 11. Darknet / Anonymous Communication

| Protocol | Era | Description | Interesting Quality | Revival Potential | Status |
|----------|-----|-------------|--------------------|--------------------|--------|
| **Freenet** | 2000-present | Distributed encrypted datastore. | Stores data without knowing what it is. Plausible deniability by design. | **High** - Privacy focus more relevant than ever. | Alive |
| **RetroShare** | 2006-present | Friend-to-friend encrypted network. | Trust graph determines connectivity. Built-in forums, chat, file sharing. | **High** - Full-featured F2F platform. Active development. | Alive |
| **Tox** | 2013-present | Encrypted P2P messenger. No servers. DHT-based. | No registration. No phone number. Fully decentralized. | **High** - Privacy-first design. | Alive |
| **WASTE** | 2003 | Justin Frankel's small trusted darknet. | Encrypted mesh between trusted friends. Minimalist design. | **Medium** - Concept needs revival. | Dead |
| **MUTE** | 2002 | Anonymous file sharing via encrypted routing. | Hidden source/destination through intermediate nodes. | **Medium** - Anonymity concept ahead of its time. | Dying |
| **I2P** | 2003-present | Invisible Internet Project. Anonymous overlay network. | Garlic routing. Hidden services. Tunnel-based architecture. | **High** - Active development. Used by privacy-conscious users. | Alive |
| **Tor (Onion Routing)** | 2002-present | The Onion Router. Anonymous browsing. | Layered encryption. Hidden services. | **High** - Gold standard for anonymity. | Alive |

---

## 12. Other Notable Protocols

| Protocol | Era | Description | Interesting Quality | Revival Potential | Status |
|----------|-----|-------------|--------------------|--------------------|--------|
| **WebFinger** | 2010s | RFC 7033. Discover user profiles via email. | Links identity across services. Federated social networking foundation. | **High** - Used by Mastodon/ActivityPub ecosystem. | Alive |
| **ActiveX/DCOM** | 1990s | Microsoft's distributed objects. | Remote procedure calls across networks. Component reuse. | **Low** - Security nightmare. Concept lives on in gRPC/REST. | Dead |
| **NFS** | 1984 | Network File System (Sun). | Mount remote filesystems locally. Stateless protocol. | **High** - Still widely used in Unix/Linux. | Alive |
| **AFS** | 1984 | Andrew File System. | Large-scale distributed filesystem. Caching client. Kerberos auth. | **Medium** - Used in academia. Predecessor to modern distributed FS. | Alive (niche) |
| **DAP** | 1981 | OSI Directory Access Protocol. | Precursor to LDAP. X.500 directory services. | **Low** - LDAP won completely. | Dead |
| **WHOIS** | 1982 | Domain/contact lookup protocol. | Simple text-based query. Decentralized registrars. | **Medium** - Still used but being replaced by RDAP. | Alive (declining) |
| **NTP** | 1985 | Network Time Protocol. | Distributed clock synchronization. Byzantine fault tolerant. | **High** - Still essential. PTP is the modern version. | Alive |
| **SNMP** | 1988 | Simple Network Management Protocol. | UDP-based network monitoring. MIB trees. | **High** - Still dominant for network management. | Alive |
| **LDAP** | 1993 | Lightweight Directory Access Protocol. | Hierarchical directory services. Authentication backend. | **High** - Still essential for enterprise identity. | Alive |
| **IRC** | 1988 | Internet Relay Chat. | Channel-based real-time chat. Federated servers. Simple text protocol. | **High** - Still used. Inspires modern chat (Slack, Discord). | Alive |
| **Telnet** | 1969 | Remote terminal access. | Simplest remote login. Works everywhere. | **Medium** - Replaced by SSH but concept is timeless. | Alive (legacy) |
| **Rlogin** | 1981 | Remote login. Trusted host authentication. | Simpler than Telnet. rhosts-based auth. | **Low** - Security issues. | Dead |
| **TACACS** | 1983 | Terminal Access Controller Access Control System. | Centralized authentication for network devices. | **Low** - Replaced by TACACS+ and RADIUS. | Legacy |
| **RADIUS** | 1997 | Remote Authentication Dial-In User Service. | AAA protocol. Centralized auth for ISPs. | **High** - Still widely used. | Alive |
| **Syslog** | 2001 | System logging protocol (RFC 3164/5424). | UDP-based log collection. Simple and universal. | **High** - Still essential for logging infrastructure. | Alive |

---

## Quick Reference: Highest Revival Potential

These protocols have the best combination of documentation, simplicity, and modern relevance:

1. **OSCAR** - Best documented old IM protocol. NINA wiki community actively maintaining it.
2. **Gnutella** - Fully decentralized. No central failure point. Anti-censorship.
3. **ZMODEM/Kermit** - Serial file transfer seeing retro revival with WiModem232.
4. **Gopher** - Spiritual ancestor of Gemini. Active community. Dead simple.
5. **Finger** - The original "presence" protocol. Conceptually ahead of its time.
6. **XMPP/Jingle** - Already open standard. Federated. VoIP capable. Underused.
7. **IAX** - Single-port NAT-friendly VoIP. Elegant design.
8. **Soulseek** - Still running. Community-driven music discovery.
9. **UUCP** - Delayed-delivery model. Great for low-connectivity scenarios.
10. **Freenet** - Privacy-first distributed storage. More relevant than ever.
11. **Tox** - No servers, no phone number, fully encrypted P2P messaging.
12. **9P** - "Everything is a file." Modern IoT relevance.

---

## Sources & Further Reading

- [NINA Wiki (OSCAR documentation)](https://nina.chat/)
- [Kermit Project](https://kermitproject.org/)
- [Gopher/Overbite Project](https://gopherproject.org/)
- [Soulseek Protocol Documentation](https://nicotine-plus.org/doc/SLSKPROTOCOL.html)
- [Hackaday - Forgotten Internet series](https://hackaday.com)
- [RetroShare](https://retroshare.cc/)
- [Tox](https://tox.chat/)
- [Freenet](https://freenetproject.org/)
- [Gemini Protocol](https://gemini.circumlunar.space/)
