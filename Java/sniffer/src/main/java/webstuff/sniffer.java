package webstuff;

import org.pcap4j.core.*;
import org.pcap4j.core.PcapNetworkInterface.PromiscuousMode;
import org.pcap4j.packet.Packet;

/**
 * this a simple packet sniffer using Pcap4j
 */

public class sniffer 
{

    private static final String PCAP_FILE_KEY = sniffer.class.getName() + ".pcapFile";
    private static final int SNAPLEN = 65536;
    private static final PromiscuousMode MODE = PromiscuousMode.PROMISCUOUS;
    private static final int TIMEOUT = 10;

    public static void main( String[] args) throws PcapNativeException, NotOpenException 
    {
        try{
            String pcapFile = System.getProperty(PCAP_FILE_KEY);
            final PcapHandle handle;
            if(pcapFile != null)
                handle = Pcaps.openOffline(pcapFile);
            else {
                PcapNetworkInterface nif = Pcaps.getDevByName("eth0"); // replace by correct interface
                System.out.println(nif.getName() + "(" +nif.getDescription() + ")");
                handle = nif.openLive(SNAPLEN, MODE, TIMEOUT);
            }

            PacketListener listener = new PacketListener(){
                @Override
                public void gotPacket(Packet packet){
                    System.out.println(handle.getTimestamp());
                    System.out.println(packet);
                }
            };
            handle.loop(0, listener);
        } catch (InterruptedException e){
            e.printStackTrace();
        }
    }
}
