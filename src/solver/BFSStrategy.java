package solver;
import java.util.*;

public class BFSStrategy extends SearchMethod {
	
	public BFSStrategy()
	{
		code = "BFS";
		longName = "Breadth-First Search";
		Frontier = new LinkedList<PuzzleState>();
		Searched = new LinkedList<PuzzleState>();
	}
	
	protected PuzzleState popFrontier()
	{
		//remove an item from the fringe to be searched
		PuzzleState thisState = Frontier.pop();
		//Add it to the list of searched states, so that it isn't searched again
		Searched.add(thisState);
		
		return thisState;
	}
	
	@Override
	public direction[] Solve(nPuzzle puzzle) {
		//This method uses the fringe as a queue.
		//Therefore, nodes are searched in order of cost, with the lowest cost
		// unexplored node searched next.
		//-----------------------------------------
		
		//put the start state in the Fringe to get explored.
		addToFrontier(puzzle.StartState);
		
		
		ArrayList<PuzzleState> newStates = new ArrayList<PuzzleState>();
				
		while(Frontier.size() > 0)
		{
			//get the next item off the fringe
			PuzzleState thisState = popFrontier();
			
			//is it the goal item?
			if(thisState.equals(puzzle.GoalState))
			{
				//We have found a solution! return it!
				return thisState.GetPathToState();
			}
			else
			{
				//This isn't the goal, just explore the node
				newStates = thisState.explore();
				
				for(int i = 0; i < newStates.size(); i++)
				{
					//add this state to the fringe, addToFringe() will take care of duplicates
					//
					// TODO: is this the correct way to add to frontier as specified in the Assignment: 
					// When all else is equal, nodes should be expanded according to the following order: 
					// the agent should try to move the empty cell UP before attempting LEFT, before 
					// attempting DOWN, before attempting RIGHT, in that order.
					addToFrontier(newStates.get(i));
				}
			}
		}
		
		//No solution found and we've run out of nodes to search
		//return null.
		return null;
	}
	
	public boolean addToFrontier(PuzzleState aState)
	{
		//if this state has been found before,
		if(Searched.contains(aState) || Frontier.contains(aState))
		{
			//discard it
			return false;
		}
		else
		{
			//else put this item on the end of the queue;
			Frontier.addLast(aState);
			return true;
		}
	}

}
