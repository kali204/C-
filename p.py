import boto3

# Create an EC2 instance
ec2 = boto3.client('ec2')

response = ec2.run_instances(
    ImageId='ami-12345678',  # Specify the ID of the Amazon Machine Image (AMI)
    InstanceType='t2.micro',  # Specify the instance type
    MinCount=1,
    MaxCount=1
)

# Get information about the newly created instance
instance_id = response['Instances'][0]['InstanceId']
instance_details = ec2.describe_instances(InstanceIds=[instance_id])
print(instance_details)

# Create an S3 bucket
s3 = boto3.client('s3')

bucket_name = 'my-unique-bucket-name'

response = s3.create_bucket(
    Bucket=bucket_name,
    CreateBucketConfiguration={'LocationConstraint': 'us-west-2'}
)

# Upload a file to the S3 bucket
file_path = '/path/to/myfile.txt'
object_key = 'myfile.txt'

s3.upload_file(file_path, bucket_name, object_key)

print('File uploaded successfully!')

# Create a Lambda function
lambda_client = boto3.client('lambda')

function_name = 'my-function'

response = lambda_client.create_function(
    FunctionName=function_name,
    Runtime='python3.8',
    Role='arn:aws:iam::123456789012:role/lambda-role',
    Handler='lambda_function.lambda_handler',
    Code={
        'S3Bucket': bucket_name,
        'S3Key': object_key
    },
    Description='My first Lambda function',
    Timeout=30,
    MemorySize=128
)

print(response)
