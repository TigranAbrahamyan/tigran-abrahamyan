// 1
const firstWordUppercase = (sentence) => {
  const startSpaceRegEx = /^\s+/g;
  const startSpaceLength = (sentence.match(startSpaceRegEx) ?? []).join().length;
  const splitted = sentence.replace(startSpaceRegEx, '').split(' ');

  return `${' '.repeat(startSpaceLength)} ${splitted[0].toUpperCase()} ${splitted.slice(1).join(' ')}`;
};

console.log(firstWordUppercase('Javascript is a programming language'));
console.log(firstWordUppercase(' Javascript is a programming language'));
console.log(firstWordUppercase('   Javascript is a programming language'));

// 2
const chunkArray = (array, chunkSize) => {
  if (chunkSize <= 0) {
    return array;
  }

  const chunkedArray = [];

  for (let i = 0; i < array.length; i += chunkSize) {
    chunkedArray.push(array.slice(i, chunkSize + i));
  }

  return chunkedArray;
};

console.log(chunkArray([1, 2, 3, 4], 0));
console.log(chunkArray([1, 2, 3, 4], 2));
console.log(chunkArray([1, 2, 3, 4, 5], 4));
console.log(chunkArray([1, 2, 3, 4, 5, 6, 7, 8], 3));

// 3
const sumOfObjectValues = (obj) => {
  return Object.values(obj).reduce((acc, n) => acc += (typeof n === 'number' ? n : 0), 0);
};

console.log(sumOfObjectValues({ a: 10, b: 20, c: 'string', d: 12 }));
console.log(sumOfObjectValues({ a: 10, b: 20, c: '5', d: 12 }));

// 4
const vowelsCount = (str) => {
  const vowels = 'aeiouAEIOU';

  return str.split('').reduce((acc, char) => ((vowels.includes(char) && acc++), acc), 0);
};

console.log(vowelsCount('Today is the best day of my life'));

// 5
const positiveNegativeValuesSum = (array) => {
  return array.reduce((acc, n) => (
    n >= 0 ? acc.positive += n : acc.negative += n,
    acc
  ), { positive: 0, negative: 0 });
};

console.log(positiveNegativeValuesSum([10, -12, 30, -1, -8, 0, 14, -33, 20]));

// 6
const data = [
  { id: 1, name: 'Name one', city: 'Stepanakert' },
  { id: 2, name: 'Name one', city: 'Erevan' },
  { id: 3, name: 'Name one', city: 'Moscow' },
  { id: 4, name: 'Name one', city: 'Stepanakert' },
  { id: 5, name: 'Name one', city: 'Erevan' },
];

const getUniqueCities = (data) => [...new Set(data.map(({ city }) => city))];

console.log(getUniqueCities(data));

// 7
const anagrams = (strA, strB) => {
  return sortWord(strA) === sortWord(strB);
};

const sortWord = (word) => word.replace(/[^a-zA-Z]/g, '').toLowerCase().split('').sort().join('');

console.log(anagrams('rail safety', 'fairy tales'));
console.log(anagrams('RAIL! SAFETY!', 'fairy tales'));
console.log(anagrams('Hi there', 'Bye there'));
