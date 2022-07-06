from collections import defaultdict

class Graph:
	def __init__(self,vert):
		self.graph = defaultdict(list) 
		self.V = vert

	
	def Edge(self,u,v):
		self.graph[u].append(v)

	
	def topoUtil(self,v,visit,stack):

		
		visit[v] = True

		
		for i in self.graph[v]:
			if visit[i] == False:
				self.topoUtil(i,visit,stack)

		
		stack.insert(0,v)

	
	def topo(self):
		
		visit = [False]*self.V
		stack =[]

		
		for i in range(self.V):
			if visit[i] == False:
				self.topoUtil(i,visit,stack)

		
		print (stack)

g= Graph(8)
g.Edge(5, 2);
g.Edge(5, 0);
g.Edge(4, 0);
g.Edge(4, 1);
g.Edge(2, 3);
g.Edge(3, 1);
g.Edge(2, 0);
g.Edge(3, 0);

print (" Topological Sort ")
g.topo()
