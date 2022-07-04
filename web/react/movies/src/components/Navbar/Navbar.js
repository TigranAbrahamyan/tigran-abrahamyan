import { Link } from 'react-router-dom';

import './Navbar.css';

const ITEMS = [
  { id: 1, path: '/home', name: 'Home' },
  { id: 2, path: '/movies', name: 'Movies' },
];

export const Navbar = () => {
  return (
    <nav>
      <ul>
        {ITEMS.map((item) => (
          <li key={item.id}>
            <Link to={item.path}>{item.name}</Link>
          </li>
        ))}
      </ul>
    </nav>
  );
}
