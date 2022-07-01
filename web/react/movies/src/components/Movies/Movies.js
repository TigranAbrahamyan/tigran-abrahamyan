import { MovieModal } from './frames/MovieModal';
import { MovieItems } from './frames/MovieItems';
import { MovieSearchingAdding } from './frames/MovieSearchingAdding';

import './Movies.css';

export const Movies = ({
  searchValue,
  setSearchValue,
  name,
  setName,
  description,
  setDescription,

  movies,
  modalVisibility,
  addMovie,
  deleteMovie,
  handleModalVisibility,
}) => {
  return (
    <div className="movies">
      <MovieSearchingAdding
        searchValue={searchValue}
        setSearchValue={setSearchValue}
        handleModalVisibility={handleModalVisibility}
      />

      <MovieItems
        movies={movies}
        deleteMovie={deleteMovie}
      />

      <MovieModal
        name={name}
        setName={setName}
        description={description}
        setDescription={setDescription}

        modalVisibility={modalVisibility}
        handleModalVisibility={handleModalVisibility}
        addMovie={addMovie}
      />
    </div>
  );
}
