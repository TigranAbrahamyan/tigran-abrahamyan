const http = require('http');
const port = 3000;

const server = http.createServer((req, res) => {
  if (req.method === 'GET' && req.url === '/') {
    res.setHeader('Content-Type', 'text/html');
    res.write('<h1>Home</h1>');
    res.end();
  }
});

server.listen(port, () => console.log(`Server is running on http://localhost:${port}`));
