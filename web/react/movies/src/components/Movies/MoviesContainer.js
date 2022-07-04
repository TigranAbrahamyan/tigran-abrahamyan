import React from 'react';
import _ from 'lodash';

import { MovieContext } from '../../context';
import { MoviesComponent } from './MoviesComponent';

export const MoviesContainer = () => {
  const { movies, setMovies } = React.useContext(MovieContext);
  const [ filteredMovies, setFilteredMovies ] = React.useState([]);
  const [ modalVisibility, setModalVisibility ] = React.useState(false);
  const [ moviesCount, setMoviesCount ] = React.useState(0);
  const [ searchValue, setSearchValue ] = React.useState('');
  const [ description, setDescription ] = React.useState('');
  const [ name, setName ] = React.useState('');

  React.useEffect(() => {
    const debounceFn = _.debounce(updateMovies, 1000);
    debounceFn();

    return () => debounceFn.cancel();
  }, [ searchValue ]);

  React.useEffect(() => {
    updateMovies();
    setMoviesCount(movies.length);
  }, [ movies ]);

  const updateMovies = () => {
    setFilteredMovies(movies.filter((movie) => movie.name.toLowerCase().includes(searchValue.toLowerCase())));
  };

  const clearInputFields = () => {
    setSearchValue('');
    setDescription('');
    setName('');
  };

  const handleModalVisibility = (state) => {
    setModalVisibility(state);
    clearInputFields();
  };

  const addMovie = () => {
    if (!name || !description) {
      alert('Inputs is required');
    } else {
      const newMovie = { id: Date.now(), name, description, img: '/images/test.webp' };
      setMovies([ ...movies, newMovie ]);
      handleModalVisibility(false);
    }
  };

  const deleteMovie = (id) => {
    setMovies(movies.filter((movie) => movie.id !== id));
  };

  return (
    <MoviesComponent
      searchValue={searchValue}
      setSearchValue={setSearchValue}
      name={name}
      setName={setName}
      description={description}
      setDescription={setDescription}

      movies={filteredMovies}
      moviesCount={moviesCount}
      modalVisibility={modalVisibility}
      addMovie={addMovie}
      deleteMovie={deleteMovie}
      handleModalVisibility={handleModalVisibility}
    />
  );
}
