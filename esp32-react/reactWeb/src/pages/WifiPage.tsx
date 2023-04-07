import { useEffect, useState } from "react";
import { WifiInfo, fetchWifiInfo } from "../utils/fetchServerUtils";
import { Container, Text } from "@mantine/core";

function WifiPage(){

    const [ wifiInfo, setWifiInfo ] = useState<WifiInfo>({ status: "Loading" });

    useEffect(() => {
        fetchWifiInfo()
            .then( v => setWifiInfo(v))
    }, []);

    return (
        <Container style={{ textAlign: "center" }}>
            <Text>Hello WifiPage</Text>

            { wifiInfo.status != "Loading" && (
                <>
                    <Text>status: { wifiInfo.status }</Text>
                    <Text>SSID: { wifiInfo.ssid }</Text>
                    <Text>IP: { wifiInfo.ip }</Text>
                </>
            )}
        </Container>
    )
}
    
export default WifiPage
