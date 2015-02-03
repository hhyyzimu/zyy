static int smartllb_vserver_network_equal(
                        struct smartllb_vserver *vserver,
                        const union nf_inet_addr *daddr)
{
        __be32 ip, mask;
        struct sockaddr_in *address, *netmask;
        union nf_inet_addr *ip2, *ip3;

        address = (struct sockaddr_in *)&vserver->address;
        netmask = (struct sockaddr_in *)&vserver->netmask;

        ip = address->sin_addr.s_addr;
        mask = netmask->sin_addr.s_addr;

        ip2 = (union nf_inet_addr *)&address->sin_addr.s_addr;
        ip3 = (union nf_inet_addr *)&daddr->ip;
        //printk(KERN_ERR "  <skb_addr:%pI4,vserver_addr:%pI4,\n",ip3,ip2);
        printk(KERN_ALERT "new: skb_addr:%d.%d.%d.%d  vserver_addr:%d.%d.%d.%d",NIPQUAD(daddr->ip),NIPQUAD(address->sin_addr.s_addr));

        if ((ip & mask) == (daddr->ip & mask)) {
                printk(KERN_ERR "%s\n","destip mach is ok!"); 
                return 1;
        }   

        return 0;
}

