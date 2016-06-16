
package dijkstra;

import static java.lang.Math.min;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

/**
 *
 * @author pragnesh
 */
class graph
{
    
    vertex ver[]; 	// We will create and array v vertices 
    int n; 		// Number of vertex in the graph
    int time=0;

    graph(int n)
    {   int i;
        this.n=n;
        ver=new vertex[n];
        for(i=0;i<n;i++)
            ver[i]=new vertex(i);
   
    }
	
	void initializeGraph(){
		for(int i=0;i<n;i++)
		{
			ver[i].initailizeVertex();
		}
	}
    void addEdge(int u,int v,int wt)
    {
        ver[u].a.add(new edge(v,wt));
        
    }

    void bfs(int src)
    {  
	LinkedList<vertex>q=new LinkedList();
       	// ver[src].dist=0; not required in the bfs algorithm
       	q.add(ver[src]); // enqueue the source in the queue 
       
       	while(!q.isEmpty())
       	{
		   vertex u=q.poll();	// dequeue the first element

		   for(int i=0;i<u.a.size();i++)	// look for all the adjacent vertices
		   {
		       if(ver[u.a.get(i).dest].visited==0)	//check for not visited vertices
		       {
		           q.add(ver[u.a.get(i).dest]);		// enqueue the unvisited vertices

		           System.out.println(u.a.get(i).dest+" ");
		           ver[u.a.get(i).dest].visited=1;
		       }
		   }
       }
    }

    void dfs(int src)
    {
        ver[src].visited=1;	//mark source as visited
        int i;
        for(i=0;i<ver[src].a.size();i++) //look for all adjacent vertices
        {
            if(ver[ver[src].a.get(i).dest].visited==0)	//check for unvisited vertices
            {   
				System.out.println(ver[src].a.get(i).dest+" ");
                dfs(ver[src].a.get(i).dest);	//recurssively traverse the graph from new fund vertex
            }
        }
    }

    void articul(int u)
    {   
        ver[u].visited=1;
        int children=0;
        ver[u].low=ver[u].disc=++time;
        int i;

        for(i=0;i<ver[u].a.size();i++)
        {   
			int v=ver[u].a.get(i).dest;  
			if(ver[v].visited==0)
			{ 
             
		     	children++;
		     	ver[v].parent=u;
		     	
		     	articul(v);//recurssive call
		     	
		     	ver[u].low=min(ver[u].low,ver[v].low);
		     	
		     	if(ver[u].parent==-1 && children>1)
		     	{ // if root of DFS tree has >=2 childs it is a Articulation-Point(AP)
					ver[u].ap=true;
		        	System.out.println(u);
		        }

		     	if(ver[u].parent!=-1 && ver[v].low>=ver[u].disc) 
		     	{   // if any children can not reach to ancester of the parent then parent is AP
					ver[u].ap=true;
		        	System.out.println(u);
		        }
            }
            
            else if(ver[u].parent!=v)
            {
                   ver[u].low=min(ver[u].low,ver[v].disc); 
            }
            
        }
        
    }
    
    void bellford(int src)
    {   int i;
        boolean cycle=false;
        LinkedList<vertex>q=new LinkedList();
        
        ver[src].dist=0;
        ver[src].level=0;
        q.add(ver[src]);
        
        while(!q.isEmpty())
       {
			   vertex u=q.poll();
			   u.added=false;
			   
			   for( i=0;i<u.a.size();i++)
			   {   int v=u.a.get(i).dest;
				   if(ver[v].dist>u.dist+u.a.get(i).weight)
				   {  
					   if(ver[v].added==false){
							q.add(ver[v]); //if the newly updated node is nit in queue add ele in q
							ver[v].level=u.level+1;//moved line
					   }
					   
					   ver[v].dist=u.dist+u.a.get(i).weight;
					   //ver[v].level=u.level+1;
					   
					   if(ver[v].level>n-1) 
					   {   //if value is updated even after n-1 itteration graph must have -ve weight cycle 
						   cycle=true;
						   break;
					   }
				   }
				  
			   }
			   
			   if(cycle==true)
			   {   System.out.println("Solution does not exist.");
				   break;
			   }
     }
	 
	 if(cycle==false)
	 {  System.out.println("Vertex Distace Values");
		for(i=1;i<n;i++)
			System.out.println(i+"        "+ver[i].dist);
	 }
     
    }
    
}
class vertex
{    
	 int id;
	 int visited;
	 int dist;
	 int low;
	 int disc;
	 int parent;
	 boolean added;
	 int level;
	 boolean ap;
	 ArrayList<edge>a;
	 vertex(int id)
	 {   
			parent=-1;
			this.id=id;
			visited=0;
			low=0;
			disc=0;
			ap=false;
			a=new ArrayList();
			dist=10000;
			level=0;
			added=false;
	 }
    
     void initailizeVertex()
     {
			parent=-1;
			visited=0;
			low=0;
			disc=0;
			ap=false;
			dist=10000;
			level=0;
			added=false;
	 }
}
class edge
{   
    int dest;
    
    int weight;
    edge(int dest,int weight)
    {
        this.dest=dest;
        this.weight=weight;
    }
}
public class GraphImplementation {

    public static void main(String[] args) {
        int e,v;
        int ch=1;
        Scanner scan=new Scanner(System.in);
        v=scan.nextInt();
        graph g = new graph(v+1);
        e=scan.nextInt();
        for(int i=0;i<e;i++)
        {
            int u=scan.nextInt();
            int ve=scan.nextInt();
            int wt=scan.nextInt();
            g.addEdge(u, ve, wt);
        }
        
        int scr;
                
        while(ch !=0){
			System.out.println("What you want to do"+
					"\n1:Run BFS on given graph" + 
					"\n2:Run DFS on given graph" +
					"\n3:Find Articulation Point in given graph" + 
					"\n4:Perform BFS Scanning Belman Ford " +
					"\n0:To exit the programme ");
			switch(ch){
				case 1: 	g.initializeGraph();
							System.out.println("Enter the Source");
							scr = scan.nextInt();
							g.bfs(scr);
							break;
			
				case 2:		g.initializeGraph();
							System.out.println("Enter the Source");
							scr = scan.nextInt();
							g.dfs(scr);
							break;
							
				case 3:		g.initializeGraph();
							g.articul(1);
							break;
											
				case 4:		g.initializeGraph();
							System.out.println("Enter the Source");
							scr = scan.nextInt();
							g.bfs(scr);		
							break;
							
				case 0:		return;
				
				default:	System.out.println("Invalid choice");
							ch=1;
			}
		}
    }
}


