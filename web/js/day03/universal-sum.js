const add = (first, second) => {
  if (first && second) {
    return first + second;
  }

  if (!first) {
    return add;
  }

  if (!second) {
    return calcSecondArg = (third) => third ? first + third : calcSecondArg;
  }
};

console.log('===Universal sum===');
console.log(add(7, 15)); // -> 22
console.log(add(7)(15)); // -> 22
console.log(add(7)()(15)); // -> 22
console.log(add(7)()()()(15)); // -> 22
console.log(add(7)()()()()()()()()()()()(15)); // -> 22
console.log(add()(7)(15)); // -> 22
console.log(add()()()()(7)(15)); // -> 22
console.log(add()(7)()(15)); // -> 22
console.log(add()()()()()(7)()()()(15)); // -> 22
console.log('===Universal sum===');
