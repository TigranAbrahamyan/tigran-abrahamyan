import { Routes, Route, Navigate, Outlet  } from 'react-router-dom';

import { HomePage } from '../../pages/Home';
import { MoviesPage } from '../../pages/Movies';
import { MoviePage } from '../../pages/Movie';
import { NotFoundPage } from '../../pages/NotFound';

const routes = [
  {
    path: '/',
    element: <Navigate to={'/home'} />,
    exact: true,
  },
  {
    path: '/home',
    element: <HomePage />,
    exact: false,
  },
  {
    path: '/movies',
    element: <Outlet />,
    exact: true,
    childrens: [
      { path: '', element: <MoviesPage />, exact: true },
      { path: ':id', element: <MoviePage />, exact: false },
    ],
  },
  {
    path: '*',
    element: <NotFoundPage />,
    exact: false,
  },
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
        >
          {(route.childrens ?? []).map((children) => (
            <Route
              key={children.path}
              path={children.path}
              element={children.element}
              exact={children.exact}
            />
          ))}
        </Route>
      ))}
    </Routes>
  );
}
