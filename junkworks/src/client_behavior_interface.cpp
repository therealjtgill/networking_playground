#include "junkworks/client_behavior_interface.hpp"

namespace junkworks
{
   IClientBehavior::IClientBehavior(UdpSocketWrapper & socket_wrapper)
      : socket_wrapper_(socket_wrapper)
   { }

   void IClientBehavior::update(
      const std::vector<raw_rx_payload_t<128> > & packets
   )
   {
      for (const auto & packet : packets)
      {
         process_packet(packet);
      }
   }

   void IClientBehavior::send_packet(const raw_tx_payload_t<128> & tx_packet)
   {
      socket_wrapper_(tx_packet);
   }
}
