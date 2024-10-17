using UnityEngine;

public class SatelliteSpawner : MonoBehaviour
{
    public GameObject satellitePrefab;
    public int satelliteCount = 10;
    public float minDistance = -5f;
    public float maxDistance = 5f;

    void Start()
    {
        SpawnSatellites();
    }

    void SpawnSatellites()
    {
        for (int i = 0; i < satelliteCount; ++i)
        {
            // ������ ���� ��ġ ����
            Vector3 randomLocalPosition = new Vector3(
                Random.Range(minDistance, maxDistance),
                Random.Range(minDistance, maxDistance),
                Random.Range(minDistance, maxDistance)
            );

            // ���� ���� �� �θ� ����
            GameObject satellite = Instantiate(satellitePrefab, transform);

            // ���� ��ġ ����
            satellite.transform.localPosition = randomLocalPosition;

        }
    }
}