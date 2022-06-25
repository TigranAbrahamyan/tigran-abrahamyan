const startBtn = document.querySelector('#start');
const figure = document.querySelector('#figure');
const gamePlace = document.querySelector('#game-place');
const circles = document.querySelector('#circles');

const gamePlacePosition = gamePlace.getBoundingClientRect();
const gamePlaceWidth = gamePlacePosition.right - gamePlacePosition.left;

const nickname = localStorage.getItem('nickname');

let figureMargin = 10;
let timerInterval;
let randomCircleInterval;

document.querySelector('#nickname').innerText = nickname;

document.querySelector('#logout').addEventListener('click', () => {
  localStorage.removeItem('nickname');
});

document.querySelector('#again').addEventListener('click', () => {
  window.location.reload();
});

const convertTimeToDate = time => {
  const date = new Date();
  const [ minutes, seconds, milliseconds ] = time.split(':');

  date.setMinutes(minutes);
  date.setSeconds(seconds);
  date.setMilliseconds(milliseconds);

  return date;
};

const setLeader = () => {
  const leaders = JSON.parse(localStorage.getItem('leaders')) || [];
  const findedUser = leaders.find(n => n.nickname === nickname);

  if (!findedUser) {
    leaders.push({ nickname, time: time.innerText });
    localStorage.setItem('leaders', JSON.stringify(leaders));
  } else {
    const currentTime = convertTimeToDate(time.innerText);
    const findedUserTime = convertTimeToDate(findedUser.time);

    if (currentTime.getTime() > findedUserTime.getTime()) {
      const leaderNewGoodTime = leaders.map(n => {
        if (n.nickname === nickname) {
          n.time = time.innerText;
        }

        return n;
      });

      localStorage.setItem('leaders', JSON.stringify(leaderNewGoodTime));
    }
  }
};

const stopGame = () => {
  circles.style.display = 'none';

  clearInterval(randomCircleInterval);
  clearInterval(timerInterval);

  document.removeEventListener('keydown', figureMoving);
  document.querySelector('[data-target="#exampleModalCenter"]').click();
  document.querySelector('.modal-body').innerText = `Time: ${time.innerText}`;

  setLeader();
};

const circlesSlideDown = () => {
  randomCircleInterval = setInterval(() => {
    const randomPosition = Math.floor(Math.random() * gamePlaceWidth);
    const circle = document.createElement('div');
    circles.append(circle);
    circle.style.marginLeft = `${randomPosition}px`;

    (() => {
      let position = 0;
      const currentCircleInterval = setInterval(() => {
        position += 10;
        circle.style.marginTop = `${position}px`;

        const figurePosition = figure.getBoundingClientRect();
        const circlePosition = circle.getBoundingClientRect();
        const circleXDiff = circlePosition.x - figurePosition.x;

        if (circleXDiff >= 0 && circleXDiff <= figurePosition.width && circlePosition.y >= figurePosition.y) {
          stopGame();
        }

        if (circlePosition.bottom >= gamePlacePosition.bottom) {
          circles.removeChild(circles.firstChild);
          clearInterval(currentCircleInterval);
        }
      }, 70);
    })();
  }, 1000);
};

const figureMoving = (event) => {
  if (startBtn.disabled === true) {
    const figurePosition = figure.getBoundingClientRect();

    if (event.key === 'ArrowLeft') {
      figureMargin -= 10;
      figure.style.marginLeft = `${figureMargin}px`;
    } else if (event.key === 'ArrowRight') {
      figureMargin += 10;
      figure.style.marginLeft = `${figureMargin}px`;
    }

    if (figurePosition.right >= gamePlacePosition.right || figurePosition.left <= gamePlacePosition.left) {
      stopGame();
    }
  }
};

startBtn.addEventListener('click', () => {
  circlesSlideDown();
  startBtn.disabled = true;
  const time = document.querySelector('#time');
  let minutes = 0;
  let seconds = 0;
  let milliseconds = 0;

  timerInterval = setInterval(() => {
    milliseconds += 53;
    time.innerText = `${minutes < 10 ? '0' + minutes : minutes}:${seconds < 10 ? '0' + seconds : seconds}:${milliseconds < 100 ? '0' + Math.floor(milliseconds / 10) : Math.floor(milliseconds / 10)}`;

    if (milliseconds >= 950) {
      seconds++;
      milliseconds = 0;
    }

    if (seconds >= 59) {
      minutes++;
      seconds = 0;
    }
  }, 53);
});

document.addEventListener('keydown', figureMoving);
