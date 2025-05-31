# dSync

Simple client server file syncer.


## Synchronization 
### Client side
**Order make sense!!!**
1. Detect local changes
2. Get server changes
3. Resolve conflicts
4. Upload local changes
5. Download server changes
6. Finalize sync
### Server side
1. Authenticate client
2. Recieve client changes(metadata?)
3. Send Server metadata
4. Resolve conflicts
5. Recieve files from client
6. Send files to client
7. Apply changes 
8. Acknowledgment completion
---
## TODO:
- [ ] Connect client/with server.
- [ ] Specify syncing folder with cmd line argument.
- [ ] Daemonize.
- [ ] Implement simple protocol(need to think about it).
- [ ] Think about protocol(__TCP__ or UDP?).
- [ ] Parralel files transfer.
