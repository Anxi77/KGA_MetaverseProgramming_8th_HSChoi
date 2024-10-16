using System.Collections;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using UnityEngine;

namespace SpaceShooter
{
    public class PlayerScript : MonoBehaviour
    {
        public float moveSpeed = 5f;
        public float boundaryXMinSize = -15.22f;
        public float boundaryXMaxSize = 15.22f;
        public float boundaryYMinSize = -18.62f;
        public float boundaryYMaxSize = 18.62f;
        public GameObject gameOverMessage;
        public Renderer target;
        public float rotationSpeed = 5f; // ȸ�� �ӵ� ������ ���� ���� �߰�

        private void Awake()
        {
            target = GetComponentInChildren<Renderer>();
        }

        void Update()
        {
            PlayerMove();
            PlayerRotate();
        }

        private void OnTriggerEnter2D(Collider2D collision)
        {
            if (collision.CompareTag("Enemy"))
            {
                //print("Game Over");
                //GameOver();
                Destroy(collision.gameObject);
            }
        }

        public void GameOver()
        {
            gameOverMessage.SetActive(true);
            Time.timeScale = 0;
        }

        public void PlayerMove()
        {
            float x = Input.GetAxis("Horizontal");
            float y = Input.GetAxis("Vertical");

            // �̵� ó��
            Vector3 movement = new Vector3(x, y, 0);
            transform.position += movement * moveSpeed * Time.deltaTime;

            // X�� ��� ó��
            transform.position = new Vector3(
                Mathf.Clamp(transform.position.x, boundaryXMinSize, boundaryXMaxSize),
                transform.position.y,
                transform.position.z
            );

            // Y�� ��� ó��
            transform.position = new Vector3(
                transform.position.x,
                Mathf.Clamp(transform.position.y, boundaryYMinSize, boundaryYMaxSize),
                transform.position.z
            );
        }

        public void PlayerRotate()
        {
            float x = Input.GetAxis("Horizontal");
            float y = Input.GetAxis("Vertical");

            if (x != 0 || y != 0) // �Է��� ���� ���� ȸ��
            {
                // �Է� ������ ������� ȸ�� ���� ���
                float angle = Mathf.Atan2(y, x) * Mathf.Rad2Deg - 90f;
                Quaternion targetRotation = Quaternion.Euler(0f, 0f, angle);

                // �ε巯�� ȸ�� ����
                transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, rotationSpeed * Time.deltaTime);
            }
        }
    }
}
