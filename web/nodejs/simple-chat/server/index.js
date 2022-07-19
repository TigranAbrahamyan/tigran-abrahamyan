const express = require('express');
const http = require('http');
const socket = require('socket.io');

const port = 3001;
const app = express();
const server = http.createServer(app);
const io = socket(server, {
  cors: {
    origin: 'http://localhost:3000',
  },
});

io.on('connection', (socket) => {
  socket.on('send-message', (msg) => {
    socket.broadcast.emit('send-broadcast-message', msg);
  });
});

server.listen(port, () => console.log(`Server started on http://localhost:${port}`));
