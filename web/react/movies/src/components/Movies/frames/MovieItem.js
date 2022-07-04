import { useNavigate } from 'react-router-dom';

import { Button } from '../../../lib/elements/Button';

export const MovieItem = ({ id, name, description, img, deleteMovie }) => {
  const navigate = useNavigate();

  return (
    <div>
      <img src={img} alt={name} />
      <div className="movies__items__content">
        <h1>{name}</h1>
        <p>{description}</p>
        <Button onClick={deleteMovie}>Delete</Button>
        <Button onClick={() => navigate(`/movies/${id}`)}>Go to movie</Button>
      </div>
    </div>
  );
}
