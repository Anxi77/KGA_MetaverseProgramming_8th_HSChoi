using UnityEngine;

public class BulletMove : MonoBehaviour
{
    public float velocity = 10f;
    public float lifeTime = 2f;

    private Vector3 direction;

    public void Start()
    {
        // 총알의 방향을 설정합니다.
        direction = transform.rotation * Vector3.up;

        // 총알의 회전을 방향에 맞게 설정합니다.
        float angle = Mathf.Atan2(direction.y, direction.x) * Mathf.Rad2Deg;
        transform.rotation = Quaternion.AngleAxis(angle - 90, Vector3.forward);

        // 총알의 수명을 설정합니다.
        Destroy(gameObject, lifeTime);
    }

    private void Update()
    {
        // 설정된 방향으로 총알을 이동시킵니다.
        transform.Translate(direction * velocity * Time.deltaTime, Space.World);
    }

    private void OnCollisionEnter(Collision collision)
    {
        DestroyImmediate(gameObject);
    }
}