import { createBrowserRouter, RouterProvider } from "react-router-dom";

import HomePage from "./pages/HomePage";
import NavComp from "./components/NavComp";
import WifiPage from "./pages/WifiPage";

const router = createBrowserRouter([
  {
    path: "/",
    element: <NavComp/>,
    children: [
      {
        path: "/",
        element: <HomePage />,
      },
      {
        path: "/wifi",
        element: <WifiPage />,
      }
    ]
  }
]);


export default function App() {
  return (
    <RouterProvider router={router} />
  );
}