'''
Copyright (C) 2012,2013 Scuola Superiore Sant'Anna (http://www.sssup.it) 
and Consorzio Nazionale Interuniversitario per le Telecomunicazioni 
(http://www.cnit.it).

This file is part of PyoT, an IoT Django-based Macroprogramming Environment.

PyoT is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
  
PyoT is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
 
You should have received a copy of the GNU General Public License
along with PyoT.  If not, see <http://www.gnu.org/licenses/>.

@author: Andrea Azzara' <a.azzara@sssup.it>
'''
from models.rpl import *
import networkx as nx


def DAGupdate(Net):
    from pyot.models.rest import Resource, Network
    from pyot.models.rpl import  RplGraph 
    G=nx.DiGraph(directed=True)

    parents = Resource.objects.filter(uri='/rplinfo/parents', host__active=True, host__kqueue=Net)
    import json
    for p in parents:
        print 'Searching parents for resource: ', p
        r = p.GET()
        if r.code != CONTENT:
            continue
        pNumber = r.content
        #print 'Searching parents for resource: ', p, pNumber
        
        for index in range(int(pNumber)):
            r = p.GET(query='index='+str(index))
            if r.code != CONTENT:
                continue
            prefix = r.content
            l = json.loads(prefix)
            pa = searchHost(l['eui'], Net)
            G.add_edge(shortName(p.host), pa)
    graph = RplGraph.objects.create(graph=G, net=Net)
    return graph


    
    
    