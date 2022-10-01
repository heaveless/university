const http = require('http');
const url = require("url");
const fs = require('fs');
const path = require("path");

const port = process.argv[2] || 8080;

function intializeServer(req, res) {
  const parseUrl = url.parse(req.url);
  let pathname = `.${parseUrl.pathname}`;
  const ext = path.parse(pathname).ext;


  const map = {
    ".html": "text/html",
    ".js": "text/javascript",
    ".css": "text/css"
  };

  fs.exists(pathname, function (exist) {
    if (!exist) {
      res.statusCode = 404;
      res.end(`File ${pathname} not found!`);
      return;
    }

    if (fs.statSync(pathname).isDirectory())
      pathname += "/index" + ext;

    fs.readFile(pathname, function (err, data) {
      if (err) {
        res.statusCode = 500;
        res.end(`Error getting the file: ${err}.`);
      } else {
        res.setHeader("Content-type", map[ext] || "text/plain");
        res.end(data);
      }
    })
  });
}

function bootstrap() {
  http
    .createServer(intializeServer)
    .listen(parseInt(port));
}

bootstrap();
