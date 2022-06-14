alert(`
Products:
1․ Սնիկերս - 200դր,
2․ Կոլա - 400դր,
3․ Ջերմուկ - 99.9դր
4. Շոկոլադ - 1200դր,
5. Կոնֆետ - 350դր
`);

const productCountQuestion = (product) => `How many ${product} do you want?`;

const snikersPrice = 200;
const colaPrice = 400;
const jermukPrice = 99.9;
const shocoladPrice = 1200;
const confetPrice = 350;

const snikersCount = +prompt(productCountQuestion('snikers'), 0);
const colaCount = +prompt(productCountQuestion('cola'), 0);
const jermukCount = +prompt(productCountQuestion('jermuk'), 0);
const shocoladCount = +prompt(productCountQuestion('shocolad'), 0);
const confetCount = +prompt(productCountQuestion('confet'), 0);

const totalPrice = () => {
  return (snikersCount * snikersPrice)
    + (colaCount * colaPrice)
    + (jermukCount * jermukPrice)
    + (shocoladCount * shocoladPrice)
    + (confetCount * confetPrice);
};

const printInfo = () => {
  if (totalPrice() === 0) {
    console.log('Դուք ոչինչ չեք գնել');
  } else {
    const userPrice = +prompt(`Total price that you need to pay: ${totalPrice()}դր`, 0);

    if (isNaN(userPrice)) {
      console.log('Սխալ գումարի մուտք');
    } else if (userPrice < totalPrice()) {
      console.log('Ձեր գումարը բավարար չէ գնումներ կատարելու համար');
    } else {
      console.log(`Ընդամենը: ${userPrice}`);
      console.log(`Վերադարձ: ${userPrice - totalPrice()}`);
      console.log(`Ծախս: ${totalPrice()}`);
      console.log('Ապրանքներ։');
      Boolean(snikersCount > 0) && console.log(` Սնիկերս ֊ ${snikersCount} հատ ֊ ${snikersCount * snikersPrice}դր,`);
      Boolean(colaCount > 0) && console.log(` Կոլա ֊ ${colaCount} հատ ֊ ${colaCount * colaPrice}դր,`);
      Boolean(jermukCount > 0) && console.log(` Ջերմուկ ֊ ${jermukCount} հատ ֊ ${jermukCount * jermukPrice}դր,`);
      Boolean(shocoladCount > 0) && console.log(` Շոկոլադ ֊ ${shocoladCount} հատ ֊ ${shocoladCount * shocoladPrice}դր,`);
      Boolean(confetCount > 0) && console.log(` Կոնֆետ ֊ ${confetCount} հատ ֊ ${confetCount * confetPrice}դր,`);
    }
  }
};

if (
  isNaN(snikersCount)
  || isNaN(colaCount)
  || isNaN(jermukCount)
  || isNaN(shocoladCount)
  || isNaN(confetCount)
) {
  console.log('Some product count is not a number');
} else {
  printInfo();
}
