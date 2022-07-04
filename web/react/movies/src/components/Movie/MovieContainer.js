import React from 'react'
import { useParams } from 'react-router-dom';

import { MovieContext } from '../../context';
import { MovieComponent } from './MovieComponent';

export const MovieContainer = () => {
  const { movies } = React.useContext(MovieContext);
  const [ movie, setMovie ] = React.useState({});
  const params = useParams();

  React.useEffect(() => {
    setMovie(movies.find((n) => n.id === +params.id));
  }, []);

  return (
    <MovieComponent movie={movie} />
  );
}