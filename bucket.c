#include <stdio.h>
#include <unistd.h>

#define MAX_BUCKET_SIZE 100

int main()
{
    int leak_rate, packet_size, current_bucket_size = 0;

    printf("Enter leak rate (packets per second): ");
    scanf("%d", &leak_rate);
    printf("Enter packet size (bytes): ");
    scanf("%d", &packet_size);

    while (1)
    {
        printf("Current bucket size: %d\n", current_bucket_size);
        if (current_bucket_size + packet_size <= MAX_BUCKET_SIZE)
        {
            current_bucket_size += packet_size;
            printf("Packet added, new size is %d\n", current_bucket_size);
        }
        else
        {
            printf("Bucket overflow, packet discarded\n");
        }
        current_bucket_size -= leak_rate;
        if (current_bucket_size < 0)
        {
            current_bucket_size = 0;
        }
        sleep(1);
    }
    return 0;
}
