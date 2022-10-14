// Java program to find number of persons under every employee
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class NumberEmployeeUnderManager
{
	// A hashmap to store result. It stores count of employees
	// under every employee, the count may by 0 also
	static Map<String,Integer> result =
							new HashMap<String, Integer>();

	// Driver function
	public static void main(String[] args)
	{
		Map<String, String> dataSet = new HashMap<String, String>();
		dataSet.put("A", "C");
		dataSet.put("B", "C");
		dataSet.put("C", "F");
		dataSet.put("D", "E");
		dataSet.put("E", "F");
		dataSet.put("F", "F");

		populateResult(dataSet);
		System.out.println("result = " + result);
	}

	// This function populates 'result' for given input 'dataset'
	private static void populateResult(Map<String, String> dataSet)
	{
		// To store reverse of original map, each key will have 0
		// to multiple values
		Map<String, List<String>> mngrEmpMap =
								new HashMap<String, List<String>>();

		// To fill mngrEmpMap, iterate through the given map
		for (Map.Entry<String,String> entry: dataSet.entrySet())
		{
			String emp = entry.getKey();
			String mngr = entry.getValue();
			if (!emp.equals(mngr)) // excluding emp-emp entry
			{
				// Get the previous list of direct reports under
				// current 'mgr' and add the current 'emp' to the list
				List<String> directReportList = mngrEmpMap.get(mngr);

				// If 'emp' is the first employee under 'mgr'
				if (directReportList == null)
				{
					directReportList = new ArrayList<String>();
					// add a new entry for the mngr with empty directReportList
					mngrEmpMap.put(mngr, directReportList);
				}
				directReportList.add(emp);
			}
		}

		// Now use manager-Emp map built above to populate result
		// with use of populateResultUtil()

		// note- we are iterating over original emp-manager map and
		// will use mngr-emp map in helper to get the count
		for (String mngr: dataSet.keySet())
			populateResultUtil(mngr, mngrEmpMap);
	}

	// This is a recursive function to fill count for 'mgr' using
	// mngrEmpMap. This function uses memoization to avoid re-
	// computations of subproblems.
	private static int populateResultUtil(String mngr,
							Map<String, List<String>> mngrEmpMap)
	{
		int count = 0;

		// means employee is not a manager of any other employee
		if (!mngrEmpMap.containsKey(mngr))
		{
			result.put(mngr, 0);
			return 0;
		}

		// this employee count has already been done by this
		// method, so avoid re-computation
		else if (result.containsKey(mngr))
			count = result.get(mngr);

		else
		{
			List<String> directReportEmpList = mngrEmpMap.get(mngr);
			count = directReportEmpList.size();
			for (String directReportEmp: directReportEmpList)
			count += populateResultUtil(directReportEmp, mngrEmpMap);

			result.put(mngr, count);
		}
		return count;
	}
}
