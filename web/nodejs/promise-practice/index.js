const path = require('path');
const fs = require('fs');

const writeFile = (path, data) => {
  return new Promise((res, rej) => fs.writeFile(path, data, (err) => {
    if (err) {
      return rej(err);
    }

    res();
  }));
};

const appendFile = (path, data) => {
  return new Promise((res, rej) => fs.appendFile(path, data, (err) => {
    if (err) {
      return rej(err);
    }

    res();
  }));
};

const readFile = (path) => {
  return new Promise((res, rej) => fs.readFile(path, { encoding: 'utf-8' }, (err, data) => {
    if (err) {
      return rej(err);
    }

    res(data);
  }));
};

writeFile(path.resolve(__dirname, 'test.txt'), 'line 1')
  .then(() => appendFile(path.resolve(__dirname, 'test.txt'), '\nline 2'))
  .then(() => appendFile(path.resolve(__dirname, 'test.txt'), '\nline 3'))
  .then(() => readFile(path.resolve(__dirname, 'test.txt')))
  .then((data) => console.log(data))
  .catch((err) => console.error(err));
