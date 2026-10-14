# tbaMUD browser connection proxy

tbaMUD/CircleMUD speaks Telnet over TCP. Its default game port in this repository is 4000. A browser cannot open a raw TCP/Telnet socket, so the browser client needs a WebSocket-to-Telnet proxy.

This deployment uses the maintained `maldorne/mud-web-proxy` image. It routes only the named `tbamud` destination, disables arbitrary host routing, limits the listener to localhost, and allows the GitHub Pages origin. Put a TLS reverse proxy in front of port 6200 so the browser connects using `wss://`.

## Configure

1. Copy `.env.example` to `.env`.
2. Set `TBAMUD_HOST` to the actual DNS name or IP address of the machine running tbaMUD. The GitHub Pages hostname is not the MUD server.
3. Ensure TCP port 4000 is reachable from the proxy host.
4. Start the proxy with `docker compose up -d`.
5. Configure your TLS reverse proxy to forward WebSocket traffic to `127.0.0.1:6200`, and use the resulting `wss://` endpoint in the browser client.

Do not expose port 6200 directly to the public internet without TLS and origin restrictions. The proxy and the MUD server are separate services; GitHub Pages only hosts static files.

The frontend still needs the proxy's connection protocol and actual secure WebSocket endpoint configured before live browser play can be verified.
