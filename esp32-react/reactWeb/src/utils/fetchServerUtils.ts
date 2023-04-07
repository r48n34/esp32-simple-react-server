export interface WifiInfo {
    status: string
    ssid?: string
    ip?: string
}

export async function fetchWifiInfo(): Promise<WifiInfo> {

    try {
        let res = await fetch("/api/wifi-info");
        let result = await res.json();
    
        return result
    } 
    catch (error) {
        console.log(error);
        return { 
            status: "Internal Error"
        }
    }
}