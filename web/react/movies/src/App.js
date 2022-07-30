import React from 'react';
import { BrowserRouter } from 'react-router-dom';

import { MovieContext } from './context';
import { AppRouter } from './components/AppRouter';
import { Navbar } from './components/Navbar';

import { movies } from './movies';

export const App = () => {
  const [ moviesList, setMoviesList ] = React.useState(movies);

  return (
    <MovieContext.Provider
      value={{
        movies: moviesList,
        setMovies: setMoviesList,
      }}
    >
      <BrowserRouter>
        <Navbar />
        <AppRouter />
      </BrowserRouter>
    </MovieContext.Provider>
  );
}
