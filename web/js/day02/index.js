// 1 problem
const firstWordUppercase = (sentence) => {
  const splittedSentence = sentence.split(' ');

  return splittedSentence[0].toUpperCase() + ' ' + splittedSentence.slice(1).join(' ');
};

console.log(firstWordUppercase('Javascript is a programming language'));
// 1 problem

// 2 problem
const chunkArray = (array, chunkSize) => {
  const chunkedArray = [];

  for (let i = 0; i < array.length; i += chunkSize) {
    chunkedArray.push(array.slice(i, chunkSize + i));
  }

  return chunkedArray;
};

console.log(chunkArray([1, 2, 3, 4], 2));
console.log(chunkArray([1, 2, 3, 4, 5], 4));
console.log(chunkArray([1, 2, 3, 4, 5, 6, 7, 8], 3));
// 2 problem

// 3 problem
const sumOfObjectValues = (obj) => {
  let sum = 0;

  for (const key in obj) {
    if (!isNaN(obj[key])) {
      sum += obj[key];
    }
  }

  return sum;
};

console.log(sumOfObjectValues({ a: 10, b: 20, c: 'string', d: 12 }));
// 3 problem

// 4 problem
const vowelsCount = (str) => {
  const vowels = 'aeiou';

  return str.split('').reduce((acc, char) => ((vowels.includes(char) && acc++), acc), 0);
};

console.log(vowelsCount('Today is the best day of my life'));
// 4 problem

// 5 problem
const positiveNegativeValuesSum = (array) => {
  return array.reduce((acc, n) => {
    if (n > 0) {
      acc.positive += n;
    } else {
      acc.negative += n;
    }

    return acc;
  }, { positive: 0, negative: 0 });
};

console.log(positiveNegativeValuesSum([10, -12, 30, -1, -8, 0, 14, -33, 20]));
// 5 problem

// 6 problem
const data = [
  { id: 1, name: 'Name one', city: 'Stepanakert' },
  { id: 2, name: 'Name one', city: 'Erevan' },
  { id: 3, name: 'Name one', city: 'Moscow' },
  { id: 4, name: 'Name one', city: 'Stepanakert' },
  { id: 5, name: 'Name one', city: 'Erevan' },
];

const getUniqueCities = (cities) => {
  const uniqueCities = [];

  for (let i = 0; i < cities.length; i++) {
    const isExist = uniqueCities.find(({ city }) => city === cities[i].city);
    if (!isExist) {
      uniqueCities.push(cities[i]);
    }
  }

  return uniqueCities;
};

console.log(getUniqueCities(data));
// 6 problem

// 7 problem
const anagrams = (strA, strB) => {
  return sortWord(strA) === sortWord(strB);
};

const sortWord = (word) => word.replace(/[^\w]/g, '').toLowerCase().split('').sort().join('');

console.log(anagrams('rail safety', 'fairy tales'));
console.log(anagrams('RAIL! SAFETY!', 'fairy tales'));
console.log(anagrams('Hi there', 'Bye there'));
// 7 problem
