import { Routes, Route, Navigate  } from 'react-router-dom';

import { HomePage } from '../../pages/Home';
import { MoviesPage } from '../../pages/Movies';
import { MoviePage } from '../../pages/Movie';
import { NotFoundPage } from '../../pages/NotFound';

const routes = [
  { path: '/', element: <Navigate to={'/home'} />, exact: true },
  { path: '/home', element: <HomePage />, exact: true },
  { path: '/movies', element: <MoviesPage />, exact: true },
  { path: '/movies/:id', element: <MoviePage />, exact: true },
  { path: '*', element: <NotFoundPage />, exact: false },
];

export const AppRouter = () => {
  return (
    <Routes>
      {routes.map((route) => (
        <Route
          key={route.path}
          path={route.path}
          element={route.element}
          exact={route.exact}
        />
      ))}
    </Routes>
  );
}
