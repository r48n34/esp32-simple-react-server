import { Link, Outlet } from "react-router-dom";

type NavCompProps = {
    data?: any;
}
    
function NavComp({ data }: NavCompProps){
    return (
        <>
        <div>
            <Link to="/">Home</Link>{" "}
            <Link to="/wifi">wifi</Link>
        </div>
        <Outlet />
        </>
    )
}
    
export default NavComp
