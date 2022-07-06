import { useNavigate } from 'react-router-dom';

import { Button } from '../../../lib/elements/Button';

export const MovieItem = ({ id, name, description, img, deleteMovie }) => {
  const navigate = useNavigate();

  return (
    <div>
      <img src={img} alt={name} />
      <div className="movies__items__content">
        <h1>{name.length >= 35 ? name.substr(0, 35).concat('...') : name}</h1>
        <p>{description.length >= 200 ? description.substr(0, 200).concat('...') : description}</p>
        <Button onClick={() => deleteMovie(id)}>Delete</Button>
        <Button onClick={() => navigate(`${id}`)}>Go to movie</Button>
      </div>
    </div>
  );
}
